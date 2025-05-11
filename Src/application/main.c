#include "pico/stdlib.h"

#include "FreeRTOS.h"

#include "task.h"

void vBlinkTask()
{

  for (;;)
  {

    gpio_put(PICO_DEFAULT_LED_PIN, 1);
    vTaskDelay(100);

    gpio_put(PICO_DEFAULT_LED_PIN, 0);
    vTaskDelay(100);

    gpio_put(PICO_DEFAULT_LED_PIN, 1);
    vTaskDelay(100);

    gpio_put(PICO_DEFAULT_LED_PIN, 0);
    vTaskDelay(700);
  }
}

void main()
{
  // Leave them free so OpenOCD can take over anytime
  gpio_set_function(29, GPIO_FUNC_NULL); // SWDIO
  gpio_set_function(30, GPIO_FUNC_NULL); // SWCLK

  gpio_init(PICO_DEFAULT_LED_PIN);

  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

  xTaskCreate(vBlinkTask, "Blink Task", 128, NULL, 1, NULL);

  vTaskStartScheduler();
}
