parser_files := src/json_parser.c src/main.c
test := test/test.c
file_name := tests/step1/valid.json
all: test
test: build_test_image
	docker run  --name json_parser_tests json_parser_tests
parser: build_parser_image
	docker run -it --name json_parser json_parser $(file_name)
build_test_image: Dockerfile.tester $(parser_files) $(test)
	docker build -t json_parser_tests -f Dockerfile.tester .
build_parser_image: Dockerfile.parser $(parser_files)
	docker build -t json_parser -f Dockerfile.parser .
clean:
	docker rmi -f json_parser
	docker rmi  -f json_parser_tests
	docker rm -f json_parser_tests
	docker rm -f json_parser
