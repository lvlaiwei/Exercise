NAME_MODEL = single_list_algorithm_reverse

SAVE_SRC_DIR = src
SAVE_TEMP_DIR = tmp
SAVE_BIN_DIR = bin
SAVE_LIB_DIR = lib

DEPEND_ON := ../../data_structure/single

CC := gcc
CFLAG +=  -fPIC
BUILD_INCLUDE_DIR += ./include $(DEPEND_ON)/include
BUILD += $(addprefix -I, $(BUILD_INCLUDE_DIR)) 
LINK_LIB_NAME += single_list_data
LINK_LIB_DIR += ../../data_structure/single/lib
LINK += $(addprefix -L, $(LINK_LIB_DIR)) $(addprefix -l, $(LINK_LIB_NAME)) -nostartfiles -e $(NAME_MODEL)

define check_dir
	test -d $(1) || mkdir -p $(1)
endef

all: $(NAME_MODEL)_bin $(NAME_MODEL)_lib

buidl_depend_on:
	@test -d $(DEPEND_ON)/lib || $(MAKE) -C $(DEPEND_ON)

$(SAVE_TEMP_DIR)/%.o:$(SAVE_SRC_DIR)/%.c buidl_depend_on
	@$(call check_dir, $(SAVE_TEMP_DIR))
	@$(CC) $(CFLAG) -c $< -o $@ $(BUILD)

$(NAME_MODEL)_bin: $(SAVE_TEMP_DIR)/$(NAME_MODEL).o
	@$(call check_dir, $(SAVE_BIN_DIR))
	@$(CC) $^ -o $(SAVE_BIN_DIR)/$@ $(LINK)
	
$(NAME_MODEL)_lib: $(SAVE_TEMP_DIR)/$(NAME_MODEL).o
	@$(call check_dir, $(SAVE_LIB_DIR))
	@$(AR) crv $(SAVE_LIB_DIR)/lib$(NAME_MODEL).a $^
	@$(CC) $^ -shared -o $(SAVE_LIB_DIR)/lib$(NAME_MODEL).so

clean:
	@rm -rf $(SAVE_LIB_DIR) $(SAVE_BIN_DIR) $(SAVE_TEMP_DIR)

.PHONY:$(NAME_MODEL)_bin $(NAME_MODEL)_lib clean