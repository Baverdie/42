FROM debian:bullseye

RUN apt update && apt install -y mariadb-server mariadb-client zsh gettext-base

COPY server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mkdir /entrypoint-initdb.d

COPY init.sql.template /entrypoint-initdb.d/.

RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

EXPOSE 3306

COPY entrypoint.sh .

RUN chmod +x entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]

CMD ["mysqld"]