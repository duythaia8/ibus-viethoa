/*
 * ibus-viethoa - The Viethoa engine for IBus
 *
 * Copyright (c) 2020-2021 Duy Thai, ngocduy.thai@yahoo.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#include <ibus.h>
#include "engine.h"
#include "vhutil.h"
#include "VHLogger.h"

static IBusBus *bus = NULL;
static IBusFactory *factory = NULL;

/* command line options */
static gboolean ibus = FALSE;
static gboolean verbose = FALSE;

static const GOptionEntry entries[] =
{
    { "ibus", 'i', 0, G_OPTION_ARG_NONE, &ibus, "component is executed by ibus", NULL },
    { "verbose", 'v', 0, G_OPTION_ARG_NONE, &verbose, "verbose", NULL },
    { NULL },
};

static void
ibus_disconnected_cb (IBusBus  *bus,
                      gpointer  user_data)
{
    vh_logger_log("__disconnected");
    ibus_quit ();
}


static void
init (void)
{
    ibus_init ();
    vh_logger_log("ibus initialized: %d", 2);

    bus = ibus_bus_new ();
    g_object_ref_sink (bus);
    g_signal_connect (bus, "disconnected", G_CALLBACK (ibus_disconnected_cb), NULL);
	
    factory = ibus_factory_new (ibus_bus_get_connection (bus));
    g_object_ref_sink (factory);
    ibus_factory_add_engine (factory, "viethoa", IBUS_TYPE_VIETHOA_ENGINE);

    if (ibus) {
        vh_logger_log("inus connected: %d", 3);
        ibus_bus_request_name (bus, "org.freedesktop.IBus.Viethoa", 0);
    }
    else {
        IBusComponent *component;

        component = ibus_component_new ("org.freedesktop.IBus.Viethoa",
                                        "Viethoa",
                                        "0.1.0",
                                        "GPL",
                                        "Duy Thai <duynthai@yahoo.com>",
                                        "http://code.google.com/p/ibus/",
                                        "",
                                        "ibus-viethoa");
        vh_logger_log("ibus-viethoa component created\n");
        ibus_component_add_engine (component, ibus_engine_desc_new ("viethoa", "Viethoa", "Viethoa", "vi_VN", "GPL", "Duy Thai <duynthai@yahoo.com>", PKGDATADIR"/icons/ibus-viethoa.svg", "us"));
        vh_logger_log("ibus-viethoa engine created\n ");
        ibus_bus_register_component (bus, component);
        vh_logger_log("ibus-viethoa component registered\n");
    }
}

int main2(int argc, char **argv)
{
    vh_logger_open();
    vh_logger_log("Begin to work... %d", 1);
    vh_logger_warn("Begin to work... %d", 1);
    vh_logger_error("Begin to work... %d", 1);
    vh_logger_backup();
    vh_logger_close();
    g_print("work!");

    return 0;
}
int main(int argc, char **argv)
{
    GError *error = NULL;
    GOptionContext *context;

    // open logger channel
    vh_logger_open();

    //vh_boghi_ghi_thongtin("datadir: %s", LIBEXECDIR);

    //
    vh_logger_log("ibus-viethoa started.\n");
        
    // Parse the command line 
    context = g_option_context_new ("- ibus viethoa engine");
    g_option_context_add_main_entries (context, entries, "ibus-viethoa");

    if (!g_option_context_parse (context, &argc, &argv, &error)) {
      g_print ("Option parsing failed: %s\n", error->message);
      g_error_free (error);
      return (-1);
    }

    // Go 
    init ();
    ibus_main ();
    vh_logger_log("__ibus-viethoa stopped.\n");
    uninitialize();
    // close logger channel
    vh_logger_close(); 
    return 0;
}
