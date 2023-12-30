
define make_model
	$(MAKE) -C $(addprefix $(shell pwd), $(subst ./,/,$(dir $(shell find -name "$(1).c"))))
endef

single_list_data:
	$(call make_model,single_list_data)
