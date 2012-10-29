import qualified Data.List as List
import qualified Data.Map as Map

solveCase :: Int -> IO ()
solveCase t = do
  line <- getLine
  let n = read line :: Int
  ws <- getLine >>= return . words
  let m = List.foldl' count Map.empty ws
        where count m v = Map.insertWith' (+) (read v :: Int) 1 m
  let (v, c) = List.foldl' findMaxVal (0, 0) $ Map.toList m
        where findMaxVal (mv, mc) (v, c) | c > mc = (v, c)
              findMaxVal (mv, mc) (v, c) | c == mc && v < mv = (v, c)
              findMaxVal acc _ = acc
  putStrLn $ show v ++ " " ++ show c

main = do
  line <- getLine
  let t = read line :: Int
  sequence [solveCase i | i <- [1..t]]
