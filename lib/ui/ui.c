// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.4
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_MainScreen;
lv_obj_t * ui_MenuPanel;
lv_obj_t * ui_TimeLabel;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Selector1;
lv_obj_t * ui_Data1;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Selector2;
lv_obj_t * ui_Data2;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_Selector3;
lv_obj_t * ui_Data3;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_Selector4;
lv_obj_t * ui_Data4;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_MainScreen_screen_init(void)
{
    ui_MainScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_MenuPanel = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_MenuPanel, lv_pct(100));
    lv_obj_set_height(ui_MenuPanel, lv_pct(6));
    lv_obj_set_align(ui_MenuPanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_MenuPanel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_MenuPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MenuPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeLabel = lv_label_create(ui_MenuPanel);
    lv_obj_set_width(ui_TimeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeLabel, lv_pct(0));
    lv_obj_set_y(ui_TimeLabel, lv_pct(-20));
    lv_obj_set_align(ui_TimeLabel, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_TimeLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_TimeLabel, "init...");
    lv_obj_set_style_text_letter_space(ui_TimeLabel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_TimeLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_MenuPanel);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label1, "CoccaGuo Works 2023");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xCBCBCB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_Panel1, lv_pct(50));
    lv_obj_set_height(ui_Panel1, lv_pct(48));
    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, lv_pct(6));
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Selector1 = lv_dropdown_create(ui_Panel1);
    lv_dropdown_set_options(ui_Selector1,
                            "Loading...\n--below is demo list--\nCurrent\nOC D1 Amplitude\nTemperature 1\nTemperature 2");
    lv_obj_set_width(ui_Selector1, lv_pct(80));
    lv_obj_set_height(ui_Selector1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Selector1, 0);
    lv_obj_set_y(ui_Selector1, lv_pct(5));
    lv_obj_set_align(ui_Selector1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Selector1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_font(ui_Selector1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Selector1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Selector1, &lv_font_montserrat_18, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_Data1 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Data1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Data1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Data1, 0);
    lv_obj_set_y(ui_Data1, lv_pct(10));
    lv_obj_set_align(ui_Data1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Data1, "000.000 nA");
    lv_obj_set_style_text_font(ui_Data1, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_Panel2, lv_pct(50));
    lv_obj_set_height(ui_Panel2, lv_pct(48));
    lv_obj_set_x(ui_Panel2, 0);
    lv_obj_set_y(ui_Panel2, lv_pct(6));
    lv_obj_set_align(ui_Panel2, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Selector2 = lv_dropdown_create(ui_Panel2);
    lv_dropdown_set_options(ui_Selector2, "Loading...");
    lv_obj_set_width(ui_Selector2, lv_pct(80));
    lv_obj_set_height(ui_Selector2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Selector2, 0);
    lv_obj_set_y(ui_Selector2, lv_pct(5));
    lv_obj_set_align(ui_Selector2, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Selector2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_font(ui_Selector2, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Selector2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Selector2, &lv_font_montserrat_18, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_Data2 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Data2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Data2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Data2, 0);
    lv_obj_set_y(ui_Data2, lv_pct(10));
    lv_obj_set_align(ui_Data2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Data2, "000.000 nA");
    lv_obj_set_style_text_font(ui_Data2, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_Panel3, lv_pct(50));
    lv_obj_set_height(ui_Panel3, lv_pct(48));
    lv_obj_set_align(ui_Panel3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Selector3 = lv_dropdown_create(ui_Panel3);
    lv_dropdown_set_options(ui_Selector3, "Loading...");
    lv_obj_set_width(ui_Selector3, lv_pct(80));
    lv_obj_set_height(ui_Selector3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Selector3, 0);
    lv_obj_set_y(ui_Selector3, lv_pct(5));
    lv_obj_set_align(ui_Selector3, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Selector3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_font(ui_Selector3, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Selector3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Selector3, &lv_font_montserrat_18, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_Data3 = lv_label_create(ui_Panel3);
    lv_obj_set_width(ui_Data3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Data3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Data3, 0);
    lv_obj_set_y(ui_Data3, lv_pct(10));
    lv_obj_set_align(ui_Data3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Data3, "000.000 nA");
    lv_obj_set_style_text_font(ui_Data3, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel4 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_Panel4, lv_pct(50));
    lv_obj_set_height(ui_Panel4, lv_pct(48));
    lv_obj_set_align(ui_Panel4, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Selector4 = lv_dropdown_create(ui_Panel4);
    lv_dropdown_set_options(ui_Selector4, "Loading...");
    lv_obj_set_width(ui_Selector4, lv_pct(80));
    lv_obj_set_height(ui_Selector4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Selector4, 0);
    lv_obj_set_y(ui_Selector4, lv_pct(5));
    lv_obj_set_align(ui_Selector4, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Selector4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_font(ui_Selector4, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Selector4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Selector4, &lv_font_montserrat_18, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_Data4 = lv_label_create(ui_Panel4);
    lv_obj_set_width(ui_Data4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Data4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Data4, 0);
    lv_obj_set_y(ui_Data4, lv_pct(10));
    lv_obj_set_align(ui_Data4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Data4, "000.000 nA");
    lv_obj_set_style_text_font(ui_Data4, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_MainScreen_screen_init();
    lv_disp_load_scr(ui_MainScreen);


}
