# Compilation errors

## [lun 10 apr 2023, 19:05:24, CEST]

```{bash}
/home/marco/code/pnuts/pnuts/pnuts_engine/include/pnuts_engine/log.hpp:4:10: fatal error: spdlog/spdlog.h: No such file or directory
    4 | #include <spdlog/spdlog.h>
      |          ^~~~~~~~~~~~~~~~~
```

This error only appear on desktop since the main development is done on my laptop. On laptop the error is not understandable.
This might be due to different system configurations.

### Update: [mar 11 apr 2023, 10:20:03, CEST] 

by removing and reinstalling `fmt` as

```{bash}
sudo apt-get remove libfmt-dev
sudo apt-get install libfmt-dev
```

the issue on laptop got equal to the one on desktop.

### TODO

1. solve the issue
2. check if the patch works everywhere
