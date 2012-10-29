findFirstGreaterLucky :: String -> Int
findFirstGreaterLucky n =
  
  firstGreaterPos 

countIncOps :: String -> Int
countIncOps n =
  

solveCase :: Int -> IO ()
solveCase t = do
  line <- getLine
  

main = do
  line <- getLine
  let t = read line :: Int
  sequence [solveCase i | i <- [1..t]]
