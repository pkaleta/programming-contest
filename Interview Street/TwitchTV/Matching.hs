-- Three infinite lists, corresponding to the three definitions in the problem
-- statement.

cats1 = map (\n -> product [n+2..2*n] `div` product [1..n]) [0..]

cats2 = 1 : map (\n -> sum $ zipWith (*) (reverse (take n cats2)) cats2) [1..]

cats3 = 1 : zipWith (\c n -> c*2*(2*n-1) `div` (n+1)) cats3 [1..]

main = let
  res = last . (take 10000)
  r = res `mod` 10
  in
    mapM_ (print . res) [cats1]
