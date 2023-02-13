build:
  docker build .

image:
  docker build -t lab0 .

create:
  docker run -p 80:80 -it -d --name lab0 lab0

start:
  docker start lab0

stop:
  docker stop lab0

dev:
  docker exec -it lab0 "/bin/bash"