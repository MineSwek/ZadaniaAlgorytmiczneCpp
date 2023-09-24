include makefile.config.env

# TASK need to be defined
ifndef TASK
    $(error TASK is not defined. Please set TASK to the desired value.)
endif


all: clear
	@g++ $(TASK_FOLDER)/$(TASK)/$(MAIN_FILE) -o $(BUILD_FOLDER)/$(TARGET_FILE) $(FLAGS) 2> $(BUILD_FOLDER)/$(TARGET_FILE).log || (echo "Compilation failed:" && cat $(BUILD_FOLDER)/$(TARGET_FILE).log && exit 1)
	C:/Users/Karol/Desktop/Programing/$(BUILD_FOLDER)/$(TARGET_FILE) < $(TASK_FOLDER)/$(TASK)/$(INPUT_FILE) > $(TASK_FOLDER)/$(TASK)/$(OUTPUT_FILE)
	
add:
	mkdir "$(TASK_FOLDER)/$(TASK)"
	@-robocopy "$(TEMPLATE_FOLDER)" "$(TASK_FOLDER)/$(TASK)"

clear:
	@-rm $(BUILD_FOLDER)/*.*