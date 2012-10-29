import Data.List
import qualified Data.Map as M
import Control.Monad
import Control.Monad.State
import Text.Printf

type Type = Int

main :: IO ()
main = do
  t <- readLn
  forM_ [(1::Int)..t] $ \i -> do
    _ <- getLine
    as <- liftM (f . fmap read . words) getLine
    bs <- liftM (f . fmap read . words) getLine
    let ans = solve as bs
    printf "Case #%d: %d\n" i ans

f :: [Integer] -> [(Integer,Type)]
f [] = []
f (n:m:xs) = (n, fromIntegral m) : f xs

solve :: [(Integer,Type)] -> [(Integer,Type)] -> Integer
solve xs ys = evalState (solve' xs ys) M.empty

type S = M.Map ([(Integer,Type)],[(Integer,Type)]) Integer

solve' :: [(Integer,Type)] -> [(Integer,Type)] -> State S Integer
solve' xs ys | null xs || null ys = return 0
solve' xxs@((n1,typ1):xs) yys@((n2,typ2):ys) = do
  memo <- get
  case M.lookup (xxs,yys) memo of
    Just ret -> return ret
    Nothing ->
      if typ1 == typ2
        then do
          ret <- if n1 <= n2
                 then liftM (n1+) $ solve' xs ((n2-n1,typ2):ys)
                 else liftM (n2+) $ solve' ((n1-n2,typ1):xs) ys
          modify (M.insert (xxs,yys) ret)
          return ret
        else do
          a <- solve' xs ((n2,typ2):ys)
          b <- solve' ((n1,typ1):xs) ys
          let ret = max a b
          modify (M.insert (xxs,yys) ret)
          return ret
