#pragma once
#include "../../globals.h"

class c_chams : public c_singleton<c_chams> {
private:
	enum type_t {
		material_regular,
		material_flat,
		dont_draw
	};

	bool override_material(int type, const col_t& clr, bool ignorez);
	i_material* create_material(std::string material_name, std::string shader_type, std::string material_data);

	i_material* m_regular;
	i_material* m_regular_z;

	i_material* m_flat;
	i_material* m_flat_z;
public:
	c_chams() {
		m_regular = create_material(_("wok_regular.vmt"), _("VertexLitGeneric"), _(R"#("VertexLitGeneric" {
	"$basetexture" "vgui/white_additive"
	"$ignorez"      "0"
	"$model"		"1"
	"$flat"			"0"
	"$nocull"		"1"
	"$halflambert"	"1"
	"$nofog"		"1"
	"$wireframe"	"0"
})#"));

		m_regular_z = create_material(_("wok_regular_z.vmt"), _("VertexLitGeneric"), _(R"#("VertexLitGeneric" {
	"$basetexture" "vgui/white_additive"
	"$ignorez"      "1"
	"$model"		"1"
	"$flat"			"0"
	"$nocull"		"1"
	"$halflambert"	"1"
	"$nofog"		"1"
	"$wireframe"	"0"
})#"));

		m_flat = create_material(_("wok_flat.vmt"), _("UnlitGeneric"), _(R"#("UnlitGeneric" {
	"$basetexture" "vgui/white_additive"
	"$ignorez"      "0"
	"$model"		"1"
	"$flat"			"1"
	"$nocull"		"1"
	"$selfillum"	"1"
	"$halflambert"	"1"
	"$nofog"		"1"
	"$wireframe"	"0"
})#"));

		m_flat_z = create_material(_("wok_flat_z.vmt"), _("UnlitGeneric"), _(R"#("UnlitGeneric" {
	"$basetexture" "vgui/white_additive"
	"$ignorez"      "1"
	"$model"		"1"
	"$flat"			"1"
	"$nocull"		"1"
	"$selfillum"	"1"
	"$halflambert"	"1"
	"$nofog"		"1"
	"$wireframe"	"0"
})#"));
	}

	void on_dme(i_model_render* ecx, void* context, const draw_model_state_t& state, const model_render_info_t& info, matrix3x4_t* bones, bool& should_call_original);
};
#define chams c_chams::instance()