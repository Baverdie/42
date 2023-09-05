clang -Wall -Wextra -Werror ft_putnbr.c ft_atoi.c main/main_putnbr.c -o putnbr

./putnbr "-2147483648" "-42" "-1" "0" "1" "2" "42" "420" "1234567890" > yours.output

diff yours.output putnbr.output > diff.output

cat diff.output | wc -l | tr -d " " > diff.count

head -n 2 diff.output | cut -c 3- > fail.output

tail -n 1 diff.output | cut -c 3- >> fail.output

sed -i '' '1d' fail.output

echo "\033[1;0m=======ft_putnbr======="

cat diff.count | tr -d " " | xargs -I {} test {} -eq 0 && for counter in {1..9}; do echo "\033[1;32m<<<<<<< SUCCESS >>>>>>>"; done || (echo "\033[1;31m>>>>>> FAILLURE <<<<<<<" && echo "Valeur: " | tr -d "\n" && cat fail.output | tail -n 1 && echo "ft_putnbr: " | tr -d "\n" && cat fail.output | head -n 1)

echo "\033[1;0m======================="

rm -rf yours.output diff.output diff.count putnbr fail.output