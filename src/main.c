#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_heap_caps.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_psram.h"  // <--- muss ESP-IDF PSRAM-Komponente enthalten
#include "nvs_flash.h"

static const char *TAG = "BOOT";

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());

    while (1)
    {
        size_t total_heap = heap_caps_get_total_size(MALLOC_CAP_DEFAULT);
        size_t free_heap  = heap_caps_get_free_size(MALLOC_CAP_DEFAULT);
        size_t total_psram = esp_psram_get_size();
        size_t free_psram  = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);

        ESP_LOGI(TAG, "Total heap: %d", total_heap);
        ESP_LOGI(TAG, "Free heap: %d", free_heap);
        ESP_LOGI(TAG, "Total PSRAM: %d", total_psram);
        ESP_LOGI(TAG, "Free PSRAM: %d", free_psram);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
