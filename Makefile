build-avr: main.c
	mkdir -p build
	avr-g++ -I. -Imicro_led/src/ main.c -o ./build/main.elf -mmcu=atmega328p -DF_CPU=16000000UL -Og
	avr-objcopy ./build/main.elf -O ihex ./build/main.hex

upload-avr: build-avr
	avrdude -c usbasp -p m328p -U flash:w:"./build/main.hex":a

clean:
	rm -rf build
