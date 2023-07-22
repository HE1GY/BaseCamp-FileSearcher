
all:
	@mkdir -p build
	$(MAKE) -C FileSearcher;
	$(MAKE) -C app;  

# Clean rule
clean:
	rm -rf build