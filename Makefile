.PHONY: clean All

All:
	@echo "----------Building project:[ exercise - Debug ]----------"
	@cd "4_factory\exercise" && "$(MAKE)" -f  "exercise.mk"
clean:
	@echo "----------Cleaning project:[ exercise - Debug ]----------"
	@cd "4_factory\exercise" && "$(MAKE)" -f  "exercise.mk" clean
