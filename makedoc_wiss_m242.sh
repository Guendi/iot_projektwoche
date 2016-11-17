PATH=$HOME/.cabal/bin:$PATH
pandoc -s README.md -o kurs_wiss_m242.html --toc --toc-depth 2 -N -c style_wiss.css --filter pandoc-include --section -t html5 --self-contained
