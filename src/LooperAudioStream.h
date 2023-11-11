#ifndef LOOPERAUDIOSTREAM
#define LOOPERAUDIOSTREAM

#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/audio_stream.hpp>

using namespace godot;

class LooperAudioStream : public AudioStreamPlayer {
    GDCLASS(LooperAudioStream,AudioStreamPlayer);


    protected:
        static void _bind_methods();
    private:
        float loop_start;
        float loop_end;
        int loop_amount;
        bool looping;
        bool indefinite_loop;
        int current_loop;
    public:
        LooperAudioStream();
        ~LooperAudioStream();
        void update_loopstream();
        void _notification(int p_what);
        void set_loop_amount(int loops);
        int get_loop_amount();
        void set_loop_start(const float _loop_start);
        float get_loop_start();
        void set_loop_end(const float _loop_end);
        float get_loop_end();
        void set_looping(bool is_looping);
        bool get_looping();
        void set_indefinite_loop(bool is_indefinite);
        bool get_indefinite_looping();
        void reset_loop();
        String get_audio_length_in_minutes();


};

#endif