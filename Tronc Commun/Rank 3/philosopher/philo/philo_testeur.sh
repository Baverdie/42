echo "=================================="
echo "||\t\033[1;92mPHILOSOPHER\033[0m\t\t||"
echo "=================================="

echo "=================================="
echo "||        Error managment       ||"
echo "=================================="

echo "\033[1;93mEmpty philo : \033[0m./philo"
./philo

echo "\033[1;93mZero value 1: \033[0m./philo"
./philo 0 0 0 0

echo "\033[1;93mZero value 2: \033[0m./philo"
./philo 2 410 200 200 0

echo "\033[1;93mNegative test 1: \033[0m./philo -2 420 200 200 1"
./philo -2 420 200 200 1

echo "\033[1;93mNegative test 2: \033[0m./philo 2 -420 200 200 1"
./philo 2 -420 200 200 1

echo "\033[1;93mNon digit test 1: \033[0m./philo pouet 420 200 200 1"
./philo pouet 420 200 200 1

echo "\033[1;93mNon digit test 2: \033[0m./philo 2 420 200 ping 1"
./philo 2 420 200 ping 1

echo "\033[1;93mZero test 1: \033[0m./philo 0 420 200 200 1"
./philo 0 420 200 200 1

echo "\033[1;93mZero test 2: \033[0m./philo 2 420 0 200 1"
./philo 2 420 0 200 1

echo "\033[1;93mZero test 3: \033[0m./philo 2 420 200 200 0"
./philo 2 420 200 200 0

echo "\033[1;93mSign test 1: \033[0m./philo +-2 420 200 200 1"
./philo +-2 420 200 ping 1

echo "\033[1;93mSign test 2: \033[0m./philo 4+2 420 200 200 1"
./philo +-2 420 200 ping 1

echo "\033[1;93mSign test 3: \033[0m./philo +2 420 200 200 1"
./philo +2 420 200 200 1

rm -rf logs/
mkdir logs

echo "=================================="
echo "||          Basic Test          ||"
echo "=================================="

echo "\033[1;93mONE philo: \033[0m./philo 1 800 200 200 1"
./philo 1 800 200 200 1
echo "Should \e[1;31mDIE\e[0m"

echo "\033[1;93mEnough time: \033[0m./philo 4 410 200 200 1"
./philo 4 410 200 200 1
echo "Should \e[1;34mLIVE\e[0m"

echo "\033[1;93mJust enough time: \033[0m./philo 4 305 200 300 1"
./philo 4 305 200 300 1
echo "Should \e[1;34mLIVE\e[0m"

echo "\033[1;93mNot enough time: \033[0m./philo 2 300 200 300 5 | grep \"dead\""
./philo 2 300 200 200 5 | grep "dead"
echo "Should \e[1;31mDIE\e[0m"

echo "\033[1;93mNot enough time: \033[0m./philo 4 310 200 100 5 | grep \"dead\""
./philo 2 310 200 100 5 | grep "dead"
echo "Should \e[1;31mDIE\e[0m"

echo "\033[1;93mEating 10 times: \033[0m./philo 6 410 200 200 10 | grep \"eating\" | wc -l"
./philo 6 410 200 200 10 > logs/logs_eating10
cat logs/logs_eating10 | grep "eating" | wc -l
echo "Should \e[1;32mEAT 60 TIME\e[0m"

echo "\033[1;93mEating 7 times: \033[0m./philo 5 800 200 200 7 | grep \"dead\" | wc -l"
./philo 5 800 200 200 7 > logs/logs_eating7
cat logs/logs_eating7 | grep "dead" | wc -l
echo "Should have 0 \e[1;31mDIE\e[0m"

echo "=================================="
echo "||         Advance Test         ||"
echo "=================================="

echo "\033[1;93mEVEN philo 10 times:\033[0m./philo 4 410 200 200 7 | grep \"dead\" | wc -l"
for i in `seq 1 10`
do
    ./philo 4 410 200 200 7 >> logs/logs_even10
    var=$(cat logs/logs_even10 | grep "dead" | wc -l)
    dead=$(($dead + $var))
done
if [ "$dead" = "0" ]
then
echo "\033[1;92mTEST PASS: ${dead}/10 dead.\033[0m\n"
else
echo "\033[1;91mTEST FAIL: ${dead}/10 dead.\033[0m\n"
fi

dead=0

echo "\033[1;93mODD philo 10 times:\033[0m./philo 5 800 200 200 7 | grep \"dead\" | wc -l"
for i in `seq 1 10`
do
    ./philo 5 800 200 200 7 > logs/logs_odd10
    var=$(cat logs/logs_odd10 | grep "dead" | wc -l)
    dead=$(($dead + $var))
done
if [ "$dead" = "0" ]
then
echo "\033[1;92mTEST PASS: ${dead}/10 dead.\033[0m\n"
else
echo "\033[1;91mTEST FAIL: ${dead}/10 dead.\033[0m\n"
fi