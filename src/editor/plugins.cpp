#define LUMIX_NO_CUSTOM_CRT
#include "core/allocator.h"
#include "editor/studio_app.h"
#include "editor/world_editor.h"

#include "imgui/imgui.h"


using namespace Lumix;

struct EditorPlugin : StudioApp::GUIPlugin {
	EditorPlugin(StudioApp& app) : m_app(app) {}

	void onGUI() override {
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_FirstUseEver);
		if (ImGui::Begin("Project generator (Online)")) {
			ImGui::TextUnformatted("Hello world");
			
		}
		ImGui::End();
	}
	
	const char* getName() const override { return "projectgen"; }

	StudioApp& m_app;
	bool m_checked_projecttype = false;
	string m_project_path;
};


LUMIX_STUDIO_ENTRY(projectgen)
{
	WorldEditor& editor = app.getWorldEditor();

	auto* plugin = LUMIX_NEW(editor.getAllocator(), EditorPlugin)(app);
	app.addPlugin(*plugin);
	return nullptr;
}
