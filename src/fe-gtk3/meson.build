hexchat_gtk3_sources = [
  'fe-gtk3.c',
  'app.c',
]

gtk_dep = dependency ('gtk+-3.0', version: '>= 3.24')

executable (
  meson.project_name (),
  hexchat_gtk3_sources,
  dependencies: [
    gtk_dep,
    hexchat_common_dep
  ],
  install: true
)
