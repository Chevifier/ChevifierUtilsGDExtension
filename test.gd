extends Chevifier

func _ready():
	start_test()
	print("In Seconds: ", $LAS.get_stream().get_length())
	print("In Minutes: ",$LAS.get_audio_length_in_minutes())




func _on_looper_audio_stream_loop_occured(loop):
	print("loop index %d happened" % loop)
