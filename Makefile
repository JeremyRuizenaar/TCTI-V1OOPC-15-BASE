.PHONY: clean All

All:
	@echo "----------Building project:[ 13-01-rational-opdracht -  ]----------"
	@cd "13-01-rational-opdracht" && "$(MAKE)" -f  "13-01-rational-opdracht.mk"
clean:
	@echo "----------Cleaning project:[ 13-01-rational-opdracht -  ]----------"
	@cd "13-01-rational-opdracht" && "$(MAKE)" -f  "13-01-rational-opdracht.mk" clean
