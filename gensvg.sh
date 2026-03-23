# Crkbd
qmk c2json ./keyboards/crkbd/keymaps/udi/keymap.c | keymap -c keymap_drawer.config.yaml parse --layer-names Base Lower Raise Adjust Sys -c 10 -q - > crkbd.layout.yaml
sed -i 's?crkbd?crkbd/r2g?' crkbd.layout.yaml
sed -i "s/'LT(RAISE,SPC)'/{t: ␣, h: Raise}/" crkbd.layout.yaml
sed -i "s/'LT(LOWER,ESC)'/{t: Esc, h: Lower}/" crkbd.layout.yaml
sed -i "s/'LT(SYS,ENT)'/{t: '\$\$mdi:keyboard-return\$\$', h: Sys}/" crkbd.layout.yaml
sed -i 's/MOD_LALT/Alt/' crkbd.layout.yaml
sed -i 's/MOD_LCTL/Ctrl/' crkbd.layout.yaml
keymap -c ./keymap_drawer.config.yaml draw crkbd.layout.yaml > crkbd.svg

