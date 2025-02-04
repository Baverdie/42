
RUN mkdir -p /etc/nginx/ssl \
		&& apt install -y openssl \ 
		&& openssl req -x509 -nodes -out /etc/nginx/ssl/certificate.crt \
		-keyout /etc/nginx/ssl/certificate.key -subj \
		"/C=FR/ST=NA/L=Angouleme/O=42/OU=42/CN=thomarna.42.fr/UID=thomarna"