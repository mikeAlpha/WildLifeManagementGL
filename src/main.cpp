// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <iostream>

// #include "Shader.h"
// #include "Mesh.h"
// #include "CircleMesh.cpp"

// unsigned int WIDTH = 1366, HEIGHT = 768;

// void framebuffer_size_callback(GLFWwindow*, int, int);
// glm::vec3 CheckMouseSelection(GLFWwindow* window, glm::mat4 projection, glm::mat4 view);
// bool IntersectRayAABB(const glm::vec3& rayOrigin, const glm::vec3& rayDir,
//     const glm::vec3& boxMin, const glm::vec3& boxMax);

// int main() {
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ecosystem 3D", NULL, NULL);
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//     gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

//     glEnable(GL_DEPTH_TEST);

//     //Shader shader("../../shaders/vertex.glsl", "../../shaders/fragment.glsl");

//     Shader shader("D:\\GameDev\\WildLifeGameGL\\shaders\\vertex.glsl", "D:\\GameDev\\WildLifeGameGL\\shaders\\fragment.glsl");

//     //Shader lightShader("../../shaders/emitv.glsl", "../../shaders/emitf.glsl");
//     Shader lightShader("D:\\GameDev\\WildLifeGameGL\\shaders\\emitv.glsl", "D:\\GameDev\\WildLifeGameGL\\shaders\\emitf.glsl");

//     float cubeVertices[] = {
//         // positions          // normals
//        // Front face
//     -0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
//      0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
//      0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
//     -0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,

//     // Back face
//     -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
//      0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
//      0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
//     -0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,

//     // Left face
//     -0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
//     -0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
//     -0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
//     -0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,

//     // Right face
//      0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
//      0.5f, -0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
//      0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
//      0.5f,  0.5f, -0.5f,   1.0f,  0.0f,  0.0f,

//      // Top face
//      -0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,
//      -0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,
//       0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,
//       0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,

//       // Bottom face
//       -0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f
//     };

//     float lightVertices[] = {
//         // positions          // normals
//        // Front face
//     -0.1f, -0.1f,  0.1f,   0.0f,  0.0f,  1.0f,
//      0.1f, -0.1f,  0.1f,   0.0f,  0.0f,  1.0f,
//      0.1f,  0.1f,  0.1f,   0.0f,  0.0f,  1.0f,
//     -0.1f,  0.1f,  0.1f,   0.0f,  0.0f,  1.0f,

//     // Back face
//     -0.1f, -0.1f, -0.1f,   0.0f,  0.0f, -1.0f,
//      0.1f, -0.1f, -0.1f,   0.0f,  0.0f, -1.0f,
//      0.1f,  0.1f, -0.1f,   0.0f,  0.0f, -1.0f,
//     -0.1f,  0.1f, -0.1f,   0.0f,  0.0f, -1.0f,

//     // Left face
//     -0.1f, -0.1f, -0.1f,  -1.0f,  0.0f,  0.0f,
//     -0.1f, -0.1f,  0.1f,  -1.0f,  0.0f,  0.0f,
//     -0.1f,  0.1f,  0.1f,  -1.0f,  0.0f,  0.0f,
//     -0.1f,  0.1f, -0.1f,  -1.0f,  0.0f,  0.0f,

//     // Right face
//      0.1f, -0.1f, -0.1f,   1.0f,  0.0f,  0.0f,
//      0.1f, -0.1f,  0.1f,   1.0f,  0.0f,  0.0f,
//      0.1f,  0.1f,  0.1f,   1.0f,  0.0f,  0.0f,
//      0.1f,  0.1f, -0.1f,   1.0f,  0.0f,  0.0f,

//      // Top face
//      -0.1f,  0.1f, -0.1f,   0.0f,  1.0f,  0.0f,
//      -0.1f,  0.1f,  0.1f,   0.0f,  1.0f,  0.0f,
//       0.1f,  0.1f,  0.1f,   0.0f,  1.0f,  0.0f,
//       0.1f,  0.1f, -0.1f,   0.0f,  1.0f,  0.0f,

//       // Bottom face
//       -0.1f, -0.1f, -0.1f,   0.0f, -1.0f,  0.0f,
//       -0.1, -0.1f,  0.1f,   0.0f, -1.0f,  0.0f,
//        0.1f, -0.1f,  0.1f,   0.0f, -1.0f,  0.0f,
//        0.1f, -0.1f, -0.1f,   0.0f, -1.0f,  0.0f
//     };


//     unsigned int cubeIndices[] = {
//         0, 1, 2, 2, 3, 0,       // front
//         4, 5, 6, 6, 7, 4,       // back
//         8, 9,10,10,11, 8,       // left
//        12,13,14,14,15,12,       // right
//        16,17,18,18,19,16,       // top
//        20,21,22,22,23,20        // bottom
//     };

//     Mesh mesh(cubeVertices, sizeof(cubeVertices) / sizeof(float), cubeIndices, sizeof(cubeIndices) / sizeof(unsigned int));

//     Mesh lightMesh(lightVertices, sizeof(lightVertices) / sizeof(float), cubeIndices, sizeof(cubeIndices) / sizeof(unsigned int));

//     //Mesh* circle = CreateCircle(0.5f, 64);

//     glm::vec3 cubeMin = glm::vec3(-0.5f, -0.5f, -0.5f);
//     glm::vec3 cubeMax = glm::vec3(0.5f, 0.5f, 0.5f);
//     glm::vec3 cubePosition = glm::vec3(0);

//     glm::vec3 lightMin = glm::vec3(-0.1f, -0.1f, -0.1f);
//     glm::vec3 lightMax = glm::vec3(0.1f, 0.1f, 0.1f);
//     glm::vec3 lightPosition = glm::vec3(0.5f, 0.5f, 2.0f);

//     bool IsObjectSelected = false;

//     while (!glfwWindowShouldClose(window)) {
//         float time = glfwGetTime();

//         glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         shader.use();

//         glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0.0, -3));
//         glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

//         glm::mat4 model, lightModel;
//         glm::vec3 camPos = glm::vec3(0.0f, 0.0f, 3.0f);

//         bool isPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
//         if (isPressed) {
//             glm::vec3 ray = CheckMouseSelection(window, projection, view);
            
//             glm::vec3 movedMin = cubePosition + cubeMin;
//             glm::vec3 movedMax = cubePosition + cubeMax;


//             if (IntersectRayAABB(camPos, ray, movedMin, movedMax)) {
//                 cubePosition = camPos + ray * 3.0f;
//                 IsObjectSelected = true;
//             }
//             else
//                 IsObjectSelected = false;
//         }
//         model = glm::translate(glm::mat4(1.0f), cubePosition);
//         model = glm::rotate(model, time, glm::vec3(1, 1, 0.5f));

//         shader.SetVector3("lightPos", lightPosition.x, lightPosition.y, lightPosition.z);
//         shader.SetVector3("lightColor", 0.8, 0.5f, 0.1f);
//         shader.SetVector3("viewPos", camPos.x, camPos.y,camPos.z);
//         shader.SetVector3("objectColor", 0.8, 0.1f, 0.0f);

//         shader.SetMatrix("view", view);
//         shader.SetMatrix("projection", projection);
//         shader.SetMatrix("model", model);

//         mesh.Draw();

//         lightShader.use();
//         lightShader.SetMatrix("view", view);
//         lightShader.SetMatrix("projection", projection);

//         isPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
//         if (isPressed) {
//             glm::vec3 ray = CheckMouseSelection(window, projection, view);

//             glm::vec3 lightmovedMin = lightPosition + lightMin;
//             glm::vec3 lightmovedMax = lightPosition + lightMax;

//             if (IntersectRayAABB(camPos, ray, lightmovedMin, lightmovedMax)) {
//                 lightPosition = camPos + ray * 2.0f;
//                 IsObjectSelected = true;
//             }
//             else
//                 IsObjectSelected = false;
//         }

//         lightModel = glm::translate(glm::mat4(1.0f), lightPosition);
//         lightShader.SetMatrix("model", lightModel);
//         lightMesh.Draw();

//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }

// glm::vec3 CheckMouseSelection(GLFWwindow* window, glm::mat4 projection, glm::mat4 view) {
//     double xpos, ypos;

//     //Normalize to screen space [-1,1]
//     glfwGetCursorPos(window, &xpos, &ypos);
//     float x = (2.0f * xpos) / WIDTH - 1.0f;
//     float y = 1.0f - (2.0f * ypos) / HEIGHT;
//     float z = 1.0f;

//     glm::vec3 rayNDC = glm::vec3(x, y, z);
//     glm::vec4 rayClip = glm::vec4(rayNDC.x, rayNDC.y, -1.0f, 1.0f);

//     glm::vec4 ray_eye = glm::inverse(projection) * rayClip;
//     ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0f, 0.0f);

//     glm::vec3 final_ray = glm::normalize(glm::vec3(glm::inverse(view) * ray_eye));
//     return final_ray;
// }

// bool IntersectRayAABB(const glm::vec3& rayOrigin, const glm::vec3& rayDir,
//     const glm::vec3& boxMin, const glm::vec3& boxMax) {
//     float tmin = (boxMin.x - rayOrigin.x) / rayDir.x;
//     float tmax = (boxMax.x - rayOrigin.x) / rayDir.x;

//     if (tmin > tmax) std::swap(tmin, tmax);

//     float tymin = (boxMin.y - rayOrigin.y) / rayDir.y;
//     float tymax = (boxMax.y - rayOrigin.y) / rayDir.y;

//     if (tymin > tymax) std::swap(tymin, tymax);

//     if ((tmin > tymax) || (tymin > tmax))
//         return false;

//     if (tymin > tmin)
//         tmin = tymin;
//     if (tymax < tmax)
//         tmax = tymax;

//     float tzmin = (boxMin.z - rayOrigin.z) / rayDir.z;
//     float tzmax = (boxMax.z - rayOrigin.z) / rayDir.z;

//     if (tzmin > tzmax) std::swap(tzmin, tzmax);

//     if ((tmin > tzmax) || (tzmin > tmax))
//         return false;

//     return true;
// }

// void framebuffer_size_callback(GLFWwindow*, int width, int height) {
//     WIDTH = width;
//     HEIGHT = height;
//     glViewport(0, 0, width, height);
// }

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <stdio.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include <GLFW/glfw3.h>

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Create window with graphics context
    float main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor()); // Valid on GLFW 3.3+ only
    GLFWwindow* window = glfwCreateWindow((int)(1280 * main_scale), (int)(800 * main_scale), "Dear ImGui GLFW+OpenGL2 example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup scaling
    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(main_scale);        // Bake a fixed style scale. (until we have a solution for dynamic style scaling, changing this requires resetting Style + calling this again)
    style.FontScaleDpi = main_scale;        // Set initial font scale. (using io.ConfigDpiScaleFonts=true makes this unnecessary. We leave both here for documentation purpose)
    io.ConfigDpiScaleFonts = true;          // [Experimental] Automatically overwrite style.FontScaleDpi in Begin() when Monitor DPI changes. This will scale fonts but _NOT_ scale sizes/padding for now.
    io.ConfigDpiScaleViewports = true;      // [Experimental] Scale Dear ImGui and Platform Windows when Monitor DPI changes.

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details. If you like the default font but want it to scale better, consider using the 'ProggyVector' from the same author!
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //style.FontSizeBase = 20.0f;
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf");
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf");
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf");
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf");
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf");
    //IM_ASSERT(font != nullptr);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();
        if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        // If you are using this code with non-legacy OpenGL header/contexts (which you should not, prefer using imgui_impl_opengl3.cpp!!),
        // you may need to backup/reset/restore other state, e.g. for current shader using the commented lines below.
        //GLint last_program;
        //glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
        //glUseProgram(0);
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        //glUseProgram(last_program);

        // Update and Render additional Platform Windows
        // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
        //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
