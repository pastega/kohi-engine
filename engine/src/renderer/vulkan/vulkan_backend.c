#include "vulkan_backend.h"

#include "vulkan_types.inl"

#include "core/logger.h"

static vulkan_context context;

b8 vulkan_renderer_backend_initialize(renderer_backend* backend, const char* application_name, struct platform_state* plat_state)
{
    // TODO: custom allocator
    context.allocator = 0;

    // Setup Vulkan instance.
    VkApplicationInfo app_info = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = application_name,
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "Kohi Engine",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
    };

    VkInstanceCreateInfo create_info = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &app_info,
        .enabledExtensionCount = 0,
        .ppEnabledExtensionNames = 0,
        .enabledLayerCount = 0,
        .ppEnabledLayerNames = 0,
    };

    VkResult result = vkCreateInstance(&create_info, context.allocator, &context.instance);

    if (result != VK_SUCCESS) {
        KERROR("vkCreateInstance failed with: %u", result);
        return FALSE;
    }

    KINFO("Vulkan renderer initialized successfully.");

    return TRUE;
}

void vulkan_renderer_backend_shutdown(renderer_backend* backend)
{
}

void vulkan_renderer_backend_on_resized(renderer_backend* backend, u16 width, u16 height)
{
}

b8 vulkan_renderer_backend_begin_frame(renderer_backend* backend, f32 delta_time)
{
    return TRUE;
}

b8 vulkan_renderer_backend_end_frame(renderer_backend* backend, f32 delta_time)
{
    return TRUE;
}