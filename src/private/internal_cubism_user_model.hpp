#ifndef INTERNAL_CUBISM_USER_MODEL
#define INTERNAL_CUBISM_USER_MODEL


// ----------------------------------------------------------------- include(s)
#include <gd_cubism.hpp>

#include <Model/CubismUserModel.hpp>
#include <Motion/CubismMotion.hpp>
#include <Motion/CubismMotionQueueManager.hpp>
#include <Utils/CubismString.hpp>
#include <CubismFramework.hpp>
#include <CubismModelSettingJson.hpp>

#include <private/internal_cubism_renderer_resource.hpp>


// ------------------------------------------------------------------ define(s)
// --------------------------------------------------------------- namespace(s)
// -------------------------------------------------------------------- enum(s)
// ------------------------------------------------------------------- const(s)
// ------------------------------------------------------------------ static(s)
// ----------------------------------------------------------- class:forward(s)
class GDCubismEffect;


// ------------------------------------------------------------------- class(s)
class InternalCubismUserModel : public Csm::CubismUserModel {
    friend GDCubismUserModel;

public:
    InternalCubismUserModel(GDCubismUserModel *owner_viewport, Node *parent_node);
    virtual ~InternalCubismUserModel();

public:
    GDCubismUserModel *_owner_viewport = nullptr;
    Node* _parent_node = nullptr;

private:
    InternalCubismRendererResource _renderer_resource;
    GDCubismUserModel::moc3FileFormatVersion _moc3_file_format_version;
    String _model_pathname;
    Csm::ICubismModelSetting* _model_setting;
    Csm::csmVector<Csm::CubismIdHandle> _list_eye_blink;
    Csm::csmVector<Csm::CubismIdHandle> _list_lipsync;
    Csm::csmMap<Csm::csmString,Csm::ACubismMotion*> _map_expression;
    Csm::csmMap<Csm::csmString,Csm::ACubismMotion*> _map_motion;

public:
    bool model_load(const String &model_pathname);
    void model_load_resource();
    void update(const float delta);
    void update_node();
    void clear();

    void stop();

    void expression_set(const char* expression_id);
    void expression_stop();

    Csm::CubismMotionQueueEntryHandle motion_start(const char* group, const int32_t no, const int32_t priority);
    void motion_stop();

    virtual void MotionEventFired(const Csm::csmString& eventValue) override;

private:
    void expression_load();
    void physics_load();
    void pose_load();
    void userdata_load();
    void motion_load();

    void effect_init();
    void effect_term();
};


// ------------------------------------------------------------------ method(s)


#endif // INTERNAL_CUBISM_USER_MODEL