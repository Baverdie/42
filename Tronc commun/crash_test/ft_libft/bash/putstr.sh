gcc -Wall -Wextra -Werror ft_putchar.c ft_putstr.c main/main_putstr.c -o putstr

./putstr "a" "aab" "baa" "" " " "1234567890" "&é\"'(§è!çà)" > yours.output

diff yours.output putstr.output > diff.output

cat diff.output | wc -l | tr -d " " > diff.count

head -n 2 diff.output | cut -c 3- > fail.output

tail -n 1 diff.output | cut -c 3- >> fail.output

sed -i '' '1d' fail.output

echo "\033[1;0m=======ft_putstr======="

cat diff.count | tr -d " " | xargs -I {} test {} -eq 0 && for counter in {1..7}; do echo "\033[1;32m<<<<<<< SUCCESS >>>>>>>" && sleep 0.1; done || (echo "\033[1;31m>>>>>> FAILLURE <<<<<<<" && echo "Valeur: " | tr -d "\n" && cat fail.output | tail -n 1 && echo "ft_putnbr: " | tr -d "\n" && cat fail.output | head -n 1)

echo "\033[1;0m======================="

rm -rf yours.output diff.output diff.count putstr fail.output
