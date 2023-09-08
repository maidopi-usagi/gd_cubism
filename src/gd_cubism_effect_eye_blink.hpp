#ifndef GD_CUBISM_EFFECT_BLINK
#define GD_CUBISM_EFFECT_BLINK


// ----------------------------------------------------------------- include(s)
#include <gd_cubism.hpp>

#include <gd_cubism_effect.hpp>


// ------------------------------------------------------------------ define(s)
// --------------------------------------------------------------- namespace(s)
using namespace godot;


// -------------------------------------------------------------------- enum(s)
// ------------------------------------------------------------------- const(s)
// ------------------------------------------------------------------ static(s)
// ----------------------------------------------------------- class:forward(s)
// ------------------------------------------------------------------- class(s)
// ------------------------------------------------------------------ method(s)
class GDCubismEffectEyeBlink : public GDCubismEffect {
    GDCLASS(GDCubismEffectEyeBlink, GDCubismEffect);

protected:
    static void _bind_methods() {}

private:
    Csm::CubismEyeBlink* _eye_blink = nullptr;

public:
    virtual void _cubism_init(Csm::ICubismModelSetting* _model_setting) override {
        if(_model_setting->GetEyeBlinkParameterCount() == 0) return;
        this->_eye_blink = Csm::CubismEyeBlink::Create(_model_setting);
    }

    virtual void _cubism_term() override {
        if(this->_eye_blink != nullptr) {
            Csm::CubismEyeBlink::Delete(this->_eye_blink);
            this->_eye_blink = nullptr;
        }
    }

    virtual void _cubism_process(Csm::CubismModel* model, const float delta) override {
        if(this->_eye_blink == nullptr) return;
        if(this->_active == false) return;

        this->_eye_blink->UpdateParameters(model, delta);
    }
};


#endif // GD_CUBISM_EFFECT_BLINK