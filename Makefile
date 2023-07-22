all:
	@mkdir -p build
	$(MAKE) -C FileSearcher;
	$(MAKE) -C app;  

clean:
	rm -rf build