.PHONY: clean All

All:
	@echo "----------Building project:[ 06-opdracht_1 -  ]----------"
	@cd "06-opdracht_1" && "$(MAKE)" -f  "06-opdracht_1.mk"
clean:
	@echo "----------Cleaning project:[ 06-opdracht_1 -  ]----------"
	@cd "06-opdracht_1" && "$(MAKE)" -f  "06-opdracht_1.mk" clean
