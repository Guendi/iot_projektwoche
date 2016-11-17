PATH=$HOME/.cabal/bin:$PATH
pandoc -s README.md -o kurs_zhb.html --toc --toc-depth 2 -N -c style_zhb.css --filter pandoc-include --section -t html5 --self-contained
