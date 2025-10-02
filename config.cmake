set(CHARM_DIR "/u/ajain18/charm/netlrts-linux-x86_64")
set(BASE_DIR "/u/ajain18/l3")
set(EIGEN_DIR "/sw/spack/deltas11-2023-03/apps/linux-rhel8-zen3/gcc-11.4.0/eigen-3.4.0-vqm46bt")

set(CHARMC "${CHARM_DIR}/bin/charmc")
set(OPTS "-std=c++20 -O3 -march=native -DNDEBUG")
set(LD_OPTS "")
set(INCS "-I${BASE_DIR}")

