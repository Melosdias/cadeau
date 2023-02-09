#include <gtk/gtk.h>

GtkWidget* window;
GtkWidget* fixed;
GtkWidget* avatar;
GtkWidget* label;

GtkWidget* yesButton;
GtkWidget* yesLabel;
GtkWidget* noButton;
GtkWidget* noLabel;
GtkWidget* loveButton;
GtkWidget* loveLabel;
GtkWidget* hugButton;
GtkWidget* hugLabel;
GtkWidget* kissButton;
GtkWidget* kissLabel;
GtkWidget* continueButton;
GtkWidget* continueLabel;

GtkBuilder* builder;

void on_loveButton_clicked(GtkButton* b)
{
    gtk_image_clear(GTK_IMAGE(avatar));
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file_at_size("loveu.png", 600, 600,  NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(avatar), pixbuf);
    gtk_label_set_text(GTK_LABEL(label), "I love you more <3");
}

void on_hugButton_clicked(GtkButton* b)
{
    gtk_image_clear(GTK_IMAGE(avatar));
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file_at_size("hug.png", 600, 600,  NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(avatar), pixbuf);
    gtk_label_set_text(GTK_LABEL(label), "You smell nice~~");
}

void on_kissButton_clicked(GtkButton* b)
{
    gtk_image_clear(GTK_IMAGE(avatar));
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file_at_size("kiss.png", 600, 600,  NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(avatar), pixbuf);
    gtk_label_set_text(GTK_LABEL(label), "I want more..~");
}
void on_yesButton_clicked(GtkButton* b)
{
    gtk_image_clear(GTK_IMAGE(avatar));
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file_at_size("yes.png", 600, 600,  NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(avatar), pixbuf);

    gtk_label_set_text(GTK_LABEL(label), "OMG thank you sweety ! <3");
    gtk_widget_destroy(yesButton);
    gtk_widget_destroy(yesLabel);
    gtk_widget_destroy(noButton);
    gtk_widget_destroy(noLabel);
    gtk_widget_destroy(continueButton);
    gtk_widget_destroy(continueLabel);
    gtk_widget_show(loveButton);
    gtk_widget_set_sensitive(loveButton, TRUE);
    gtk_widget_show(loveLabel);
    gtk_widget_show(hugButton);
    gtk_widget_set_sensitive(hugButton, TRUE);
    gtk_widget_show(hugLabel);
    gtk_widget_show(kissButton);
    gtk_widget_set_sensitive(kissButton, TRUE);
    gtk_widget_show(kissLabel);
}
void on_continueButton_clicked(GtkButton* b)
{
    gtk_image_clear(GTK_IMAGE(avatar));
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file_at_size("continue.png", 600, 600,  NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(avatar), pixbuf);
    gtk_label_set_text(GTK_LABEL(label), "You're cute.. \n Do you wanna be my boyfriend ? <3");
    
    gtk_widget_show(yesButton);
    gtk_widget_show(yesLabel);
    gtk_widget_show(noButton);
    gtk_widget_show(noLabel);
    gtk_widget_hide(continueButton);
    gtk_widget_hide(continueLabel);

    gtk_label_set_text(GTK_LABEL(noLabel), "YES");
    g_signal_connect(noButton, "clicked", G_CALLBACK(on_yesButton_clicked), NULL);

}
void on_noButton_clicked(GtkButton* b)
{
    gtk_image_clear(GTK_IMAGE(avatar));
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file_at_size("no.png", 600, 600,  NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(avatar), pixbuf);
    gtk_label_set_text(GTK_LABEL(label), "Oh... \n No it must be a missclick u.u");
    
    gtk_widget_show(continueButton);
    gtk_widget_show(continueLabel);
    gtk_widget_hide(noButton);
    gtk_widget_hide(noLabel);
    gtk_widget_hide(yesButton);
    gtk_widget_hide(yesLabel);

}
int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);
    builder = gtk_builder_new_from_file("cadeau.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    if (window == NULL) printf("Nothing");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(builder, NULL);

    fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));

    yesButton = GTK_WIDGET(gtk_builder_get_object(builder, "yesButton"));
    yesLabel = GTK_WIDGET(gtk_builder_get_object(builder, "yesLabel"));
    noButton = GTK_WIDGET(gtk_builder_get_object(builder, "noButton"));
    noLabel = GTK_WIDGET(gtk_builder_get_object(builder, "noLabel"));
    loveButton = GTK_WIDGET(gtk_builder_get_object(builder, "loveButton"));
    loveLabel = GTK_WIDGET(gtk_builder_get_object(builder, "loveLabel"));
    hugButton = GTK_WIDGET(gtk_builder_get_object(builder, "hugButton"));
    hugLabel = GTK_WIDGET(gtk_builder_get_object(builder, "hugLabel"));
    kissButton = GTK_WIDGET(gtk_builder_get_object(builder, "kissButton"));
    kissLabel = GTK_WIDGET(gtk_builder_get_object(builder, "kissLabel"));
    continueButton = GTK_WIDGET(gtk_builder_get_object(builder, "continueButton"));
    continueLabel = GTK_WIDGET(gtk_builder_get_object(builder, "continueLabel"));


    label = GTK_WIDGET(gtk_builder_get_object(builder,"label"));


    avatar = GTK_WIDGET(gtk_builder_get_object(builder,"avatar"));
    gtk_image_clear(GTK_IMAGE(avatar));
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file_at_size("hello.png", 600, 600,  NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(avatar), pixbuf);


    GtkCssProvider * css = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css, "* { background-image:none; background-color:#FFD1DC;}",-1,NULL);
    GtkStyleContext * context = gtk_widget_get_style_context(yesButton);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
    context = gtk_widget_get_style_context(noButton);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
    context = gtk_widget_get_style_context(loveButton);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
    context = gtk_widget_get_style_context(hugButton);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
    context = gtk_widget_get_style_context(kissButton);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
    context = gtk_widget_get_style_context(label);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
    context = gtk_widget_get_style_context(continueButton);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_signal_connect(yesButton, "clicked", G_CALLBACK(on_yesButton_clicked), NULL);
    g_signal_connect(noButton, "clicked", G_CALLBACK(on_noButton_clicked), NULL);
    g_signal_connect(loveButton, "clicked", G_CALLBACK(on_loveButton_clicked), NULL);
    g_signal_connect(hugButton, "clicked", G_CALLBACK(on_hugButton_clicked), NULL);
    g_signal_connect(kissButton, "clicked", G_CALLBACK(on_kissButton_clicked), NULL);
     g_signal_connect(continueButton, "clicked", G_CALLBACK(on_continueButton_clicked), NULL);
    //g_signal_connect(window, "motion_notify_event", G_CALLBACK(on_mouse_move), NULL);
    
    gtk_widget_show(window);
    gtk_widget_hide(loveButton);
    gtk_widget_hide(loveLabel);
    gtk_widget_hide(hugButton);
    gtk_widget_hide(hugLabel);
    gtk_widget_hide(kissButton);
    gtk_widget_hide(kissLabel);
    gtk_widget_hide(continueButton);
    gtk_widget_hide(continueLabel);
    gtk_main();
    return EXIT_SUCCESS;
}
