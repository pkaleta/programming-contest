import System (getArgs)

calc :: Int -> Int -> IO ()
calc i n
    | i > n =
        return ()
    | i `mod` 3 == 0 && i `mod` 5 == 0 = do
        putStrLn "Hop"
        calc (i+1) n
    | i `mod` 3 == 0 = do
        putStrLn "Hoppity"
        calc (i+1) n
    | i `mod` 5 == 0 = do
        putStrLn "Hophop"
        calc (i+1) n
    | otherwise = do
        calc (i+1) n

getNumberFromFile :: String -> IO Int
getNumberFromFile fileName = readFile fileName >>= (\x -> return (read x))

main = do
    args <- getArgs
    let fileName = args !! 0
    n <- getNumberFromFile fileName
    calc 1 n

