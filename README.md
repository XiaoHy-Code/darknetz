# Prerequisites
You can run this application with real TrustZone or a simulated one by using QEMU.

**Required System**: Ubuntu-based distributions

**For simulation**, no additional hardware is needed.

**For real TrustZone, an additional board is required**. Raspberry Pi 3, HiKey Board, ARM Juno board, etc. Check this [List](https://optee.readthedocs.io/en/latest/building/devices/index.html#device-specific) for more info.

# Setup
## (1) Set up OP-TEE
1) Follow **step1** ~ **step5** in "**Get and build the solution**" to build the OP-TEE solution.
https://optee.readthedocs.io/en/latest/building/gits/build.html#get-and-build-the-solution

2) **For real boards**: If you are using boards, keep follow **step6** ~ **step7** in the above link to flash the devices. This step is device-specific.

   **For simulation**: If you have chosen QEMU-v7/v8, run the below command to start QEMU console.
```
make run
(qemu)c
```

3) Follow **step8** ~ **step9** to test whether OP-TEE works or not. Run:
```
tee-supplicant -d
xtest
```

Note: you may face OP-TEE related problem/errors during setup, please also free feel to raise issues in [their pages](https://github.com/OP-TEE/optee_os).

## (2) Build DarkneTZ
1) clone codes and datasets
```
git clone https://github.com/mofanv/darknetz.git
git clone https://github.com/mofanv/tz_datasets.git
```
Let `$PATH_OPTEE$` be the path of OPTEE, `$PATH_darknetz$` be the path of darknetz, and `$PATH_tz_datasets$` be the path of tz_datasets.

2) copy DarkneTZ to example dir
```
mkdir $PATH_OPTEE$/optee_examples/darknetz
cp -a $PATH_darknetz$/. $PATH_OPTEE$/optee_examples/darknetz/
```

3) copy datasets to root dir
```
cp -a $PATH_tz_datasets$/. $PATH_OPTEE$/out-br/target/root/
```

4) rebuild the OP-TEE

**For simulation**, to run `make run` again.

**For real boards**, to run `make flash` to flash the OP-TEE with `darknetz` to your device.

5) after you boot your devices or QEMU, test by the command 
```
darknetp
```
Note: It is NOT `darknetz` here for the command.

You should get the output:
 ```
# usage: ./darknetp <function>
 ```
Awesome! You are ready to run DNN layers in TrustZone.

# Inference
0) Confusing the weight parameters of each layer
```
darknetp confusion cfg/mnist_lenet.cfg models/mnist/mnist_lenet.weights test.weights
```
2) Inference using obfuscated weight parameters
```
darknetp classifier predict cfg/mnist.dataset cfg/mnist_lenet.cfg test.weights data/mnist/images/t_00002_c4.png
```
