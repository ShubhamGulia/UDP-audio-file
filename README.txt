Hi, WELCOME friend

Steps to follow regarding our radio transmitter - 
   Step 1 - Called from the command line using the following parameters:
	=> ./udp <audio_file> <destination_ip> <ms_delay>
	=> Example: ./udp quartet.mp3 10.200.48.206 50
   Step 2 - We hard-code two important parameters within the program:
	=>The destination port: port 44444
	=>The buffer size (and size of data we try to send at once): 1500 bytes
		->Though we change this size once for testing purposes (see Figure 1.2)
   Step 3 - We used ffmpeg to convert sample .mp3 files to .wav and .au. An example ffmpeg call used follows:
	=> ./ffmpeg -i quartet.mp3 quartet.au

If you any question mail me to sg952@njit.edu or shubham26g1994@gmail.com

Have a good one!!!