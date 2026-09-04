#include<iostream>
#include<memory>
using namespace std;

class Texture {

    string name;
    int width;
    int height;

public:

    Texture(string name, int width, int height):name(name), width(width), height(height) {
        cout << "Texture Loaded" << endl;
    }

    ~Texture() {
        cout << "Texture Released" << endl;
    }

    void display() const {
        cout << "Dimensions " << width << "x" << height << endl;
    }
};

class Shader {
  
    string name;
    string type;

public:

    Shader(string name, string type):name(name), type(type) {
        cout << "Shader Compiled" << endl;
    }

    ~Shader() {
        cout << "Shader Destroyed" << endl;
    }
};

    int getReferenceCount(const shared_ptr<Shader>& shader) {
        return shader.use_count();
    }


class AudioClip {

    string name;
    double duration;

public:

    AudioClip(string name, double duration):name(name), duration(duration) {
        cout << "AudioClip Loaded" << endl;
    }

    ~AudioClip() {
        cout << "AudioClip Released" << endl;
    }

    string getName() const {
        return name;
    }
};


int main() {

    // Part A :
    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);
    tex1->display();

    unique_ptr<Texture> tex2 = move(tex1);
    cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;


    // Part B :
    auto shader = make_shared<Shader>("main_vert", "vertex");
    cout << "Ref count: " << shader.use_count() << endl;
    {
        auto rendererRef = shader;
		cout << "Ref count: " << shader.use_count() << endl;  
		auto editorRef = shader;
		cout << "Ref count: " << shader.use_count() << endl;  
    }

    cout << "Ref count: " << shader.use_count() << endl;


    // Part C :
    auto audio = make_shared<AudioClip>("explosion", 3.5);
    weak_ptr<AudioClip> observer = audio;

    if(auto clip = observer.lock())
        cout << "Clip alive: " << clip->getName() << endl;
        audio.reset();

    if(observer.expired())
        cout << "Clip already unloaded." << endl;

    return 0;
}