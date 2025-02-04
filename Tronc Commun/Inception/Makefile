all : up

re : stop fclean all

up :
	mkdir -p /home/basverdi/data/mariadb
	mkdir -p /home/basverdi/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up -d

down :
	docker compose -f ./srcs/docker-compose.yml down -v

start :
	docker compose -f ./srcs/docker-compose.yml start

stop :
	docker compose -f ./srcs/docker-compose.yml stop

fclean :
	docker system prune -af
	docker volume rm wordpress mariadb
	rm -rf /home/basverdi/data

.PHONY re start stop up down fclean all