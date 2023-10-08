include makefile.config.env

# TASK needs to be defined
ifndef TASK
    $(error TASK is not defined. Please set TASK to the desired value.)
endif

all: clear
	@echo Compiling...
	@g++ $(TASK_FOLDER)/$(TASK)/$(MAIN_FILE) -o $(BUILD_FOLDER)/$(TARGET_FILE) || (echo Compilation failed && type $(BUILD_FOLDER)/$(TARGET_FILE).log && exit /b 1)
	@echo Compilation completed.
	@echo Running...
	@$(CURDIR)/$(BUILD_FOLDER)/$(TARGET_FILE) < $(TASK_FOLDER)/$(TASK)/$(INPUT_FILE) > $(TASK_FOLDER)/$(TASK)/$(OUTPUT_FILE)
	@echo Execution completed.

add:
	mkdir "$(TASK_FOLDER)/$(TASK)"
	@-robocopy "$(TEMPLATE_FOLDER)" "$(TASK_FOLDER)/$(TASK)"

clear:
	@del /Q "$(CURDIR)\$(BUILD_FOLDER)\*.*"
