import Data.List (sortBy)
import Data.Ord (comparing)
import Data.Time.Clock (getCurrentTime, diffUTCTime)
import System.CPUTime (getCPUTime)
import System.Mem (performGC)
import Text.Printf (printf)

data Student = Student { name :: String, grade :: Int }

sortStudents :: [Student] -> [Student]
sortStudents = sortBy (comparing (\s -> (- grade s, name s)))

printStudent :: Student -> IO ()
printStudent (Student n g) = putStrLn (n ++ " - " ++ show g)

sampleStudents :: [Student]
sampleStudents =
  [ Student "Juan"    85
  , Student "Pablo" 92
  , Student "Natalia"85
  , Student "Angel"  92
  , Student "alan"   70
  , Student "Karol"   85
  ]

main :: IO ()
main = do
  let xs = sampleStudents
  startWall <- getCurrentTime
  startCPU  <- getCPUTime

  let sorted = sortStudents xs

  putStrLn "Ordenando estudiantes (nota descendente con nombre ascendente si hay empate):"
  mapM_ printStudent sorted

  performGC

  endCPU  <- getCPUTime
  endWall <- getCurrentTime

  let wallSec = realToFrac (diffUTCTime endWall startWall) :: Double
      cpuSec  = fromIntegral (endCPU - startCPU) / 1e12 :: Double

  putStrLn ""
  printf "Tiempo total: %.6f s\n" wallSec
  printf "Tiempo de la cpu: %.6f s\n" cpuSec


