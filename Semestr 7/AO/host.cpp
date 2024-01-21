#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include <CL/cl.h>

const int vector_len = 1024;

const char kernelSourceCodeAdd[] =
"__kernel void vector_add(__global int *A, __global int *B, __global int *C) {	\n"
"  int i = get_global_id(0);													\n"
"	  C[i] = A[i] + B[i];														\n"
"}																				\n"
;

const char kernelSourceCodeMultiply[] =
"__kernel void matrixMul(__global float* C, __global float* A, __global float* B, int wA, int wB) {  \n"
"   int tx = get_global_id(0);                                                                       \n"
"    int ty = get_global_id(1);                                                                      \n"
"    int value = 0;                                                                                  \n"
"    for (int k = 0; k < wA; ++k) {                                                                  \n"
"        int elementA = A[ty * wA + k];                                                              \n"
"        int elementB = B[k * wB + tx];                                                              \n"
"        value += elementA * elementB;                                                               \n"
"    }                                                                                               \n"
"    C[ty * wA + tx] = value;                                                                        \n"
"}                                                                                                   \n"
;

const char* getErrorString(cl_int error)
{
    switch (error) {
        // run-time and JIT compiler errors
    case 0: return "CL_SUCCESS";
    case -1: return "CL_DEVICE_NOT_FOUND";
    case -2: return "CL_DEVICE_NOT_AVAILABLE";
    case -3: return "CL_COMPILER_NOT_AVAILABLE";
    case -4: return "CL_MEM_OBJECT_ALLOCATION_FAILURE";
    case -5: return "CL_OUT_OF_RESOURCES";
    case -6: return "CL_OUT_OF_HOST_MEMORY";
    case -7: return "CL_PROFILING_INFO_NOT_AVAILABLE";
    case -8: return "CL_MEM_COPY_OVERLAP";
    case -9: return "CL_IMAGE_FORMAT_MISMATCH";
    case -10: return "CL_IMAGE_FORMAT_NOT_SUPPORTED";
    case -11: return "CL_BUILD_PROGRAM_FAILURE";
    case -12: return "CL_MAP_FAILURE";
    case -13: return "CL_MISALIGNED_SUB_BUFFER_OFFSET";
    case -14: return "CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST";
    case -15: return "CL_COMPILE_PROGRAM_FAILURE";
    case -16: return "CL_LINKER_NOT_AVAILABLE";
    case -17: return "CL_LINK_PROGRAM_FAILURE";
    case -18: return "CL_DEVICE_PARTITION_FAILED";
    case -19: return "CL_KERNEL_ARG_INFO_NOT_AVAILABLE";

        // compile-time errors
    case -30: return "CL_INVALID_VALUE";
    case -31: return "CL_INVALID_DEVICE_TYPE";
    case -32: return "CL_INVALID_PLATFORM";
    case -33: return "CL_INVALID_DEVICE";
    case -34: return "CL_INVALID_CONTEXT";
    case -35: return "CL_INVALID_QUEUE_PROPERTIES";
    case -36: return "CL_INVALID_COMMAND_QUEUE";
    case -37: return "CL_INVALID_HOST_PTR";
    case -38: return "CL_INVALID_MEM_OBJECT";
    case -39: return "CL_INVALID_IMAGE_FORMAT_DESCRIPTOR";
    case -40: return "CL_INVALID_IMAGE_SIZE";
    case -41: return "CL_INVALID_SAMPLER";
    case -42: return "CL_INVALID_BINARY";
    case -43: return "CL_INVALID_BUILD_OPTIONS";
    case -44: return "CL_INVALID_PROGRAM";
    case -45: return "CL_INVALID_PROGRAM_EXECUTABLE";
    case -46: return "CL_INVALID_KERNEL_NAME";
    case -47: return "CL_INVALID_KERNEL_DEFINITION";
    case -48: return "CL_INVALID_KERNEL";
    case -49: return "CL_INVALID_ARG_INDEX";
    case -50: return "CL_INVALID_ARG_VALUE";
    case -51: return "CL_INVALID_ARG_SIZE";
    case -52: return "CL_INVALID_KERNEL_ARGS";
    case -53: return "CL_INVALID_WORK_DIMENSION";
    case -54: return "CL_INVALID_WORK_GROUP_SIZE";
    case -55: return "CL_INVALID_WORK_ITEM_SIZE";
    case -56: return "CL_INVALID_GLOBAL_OFFSET";
    case -57: return "CL_INVALID_EVENT_WAIT_LIST";
    case -58: return "CL_INVALID_EVENT";
    case -59: return "CL_INVALID_OPERATION";
    case -60: return "CL_INVALID_GL_OBJECT";
    case -61: return "CL_INVALID_BUFFER_SIZE";
    case -62: return "CL_INVALID_MIP_LEVEL";
    case -63: return "CL_INVALID_GLOBAL_WORK_SIZE";
    case -64: return "CL_INVALID_PROPERTY";
    case -65: return "CL_INVALID_IMAGE_DESCRIPTOR";
    case -66: return "CL_INVALID_COMPILER_OPTIONS";
    case -67: return "CL_INVALID_LINKER_OPTIONS";
    case -68: return "CL_INVALID_DEVICE_PARTITION_COUNT";

        // extension errors
    case -1000: return "CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR";
    case -1001: return "CL_PLATFORM_NOT_FOUND_KHR";
    case -1002: return "CL_INVALID_D3D10_DEVICE_KHR";
    case -1003: return "CL_INVALID_D3D10_RESOURCE_KHR";
    case -1004: return "CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR";
    case -1005: return "CL_D3D10_RESOURCE_NOT_ACQUIRED_KHR";
    default: return "Unknown OpenCL error";
    }
}

//program wykonywany na HOSCIE - host program
int main(void) {
    int menu_pick;
    int i, j;
    char* value;
    size_t valueSize;
    cl_uint platformCount;
    cl_platform_id* platforms;
    cl_uint deviceCount;
    cl_device_id* devices;
    cl_platform_info platformName;

    cl_int result;

    clGetPlatformIDs(0, NULL, &platformCount);
    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * platformCount);
    clGetPlatformIDs(platformCount, platforms, NULL);

    while (1) {
        system("cls");
        printf("MENU:\n1. Show platforms and devices\n2. Benchmark all platforms\n0. Exit\n");
        scanf("%d", &menu_pick);

        if (menu_pick == 0) break;
        else if (menu_pick == 1) {
            system("cls");

            printf("Available platforms: %d\n\n", platformCount);

            for (i = 0; i < platformCount; i++) {

                // Get all devices
                result = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &deviceCount);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                devices = (cl_device_id*)malloc(sizeof(cl_device_id) * deviceCount);

                result = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, deviceCount, devices, NULL);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                // Platform name
                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, NULL, NULL, &valueSize);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                value = (char*)malloc(valueSize);

                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, valueSize, value, NULL);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                printf("Platform name: %s\n", value);
                free(value);

                // Platofrm version
                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_VERSION, NULL, NULL, &valueSize);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                value = (char*)malloc(valueSize);

                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_VERSION, valueSize, value, NULL);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                printf("Platform version: %s\n", value);
                free(value);

                // Platofrm vendor
                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, NULL, NULL, &valueSize);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                value = (char*)malloc(valueSize);

                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, valueSize, value, NULL);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                printf("Platform vendor: %s\n", value);
                free(value);

                printf("Available devices: %d\n", deviceCount);

                // Print parameters of each platform
                for (j = 0; j < deviceCount; j++) {

                    // Device name
                    result = clGetDeviceInfo(devices[j], CL_DEVICE_NAME, 0, NULL, &valueSize);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    value = (char*)malloc(valueSize);

                    result = clGetDeviceInfo(devices[j], CL_DEVICE_NAME, valueSize, value, NULL);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    printf("\tDevice name: %s\n", value);
                    free(value);

                    // Device manufacturer
                    result = clGetDeviceInfo(devices[j], CL_DEVICE_VENDOR, 0, NULL, &valueSize);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    value = (char*)malloc(valueSize);

                    result = clGetDeviceInfo(devices[j], CL_DEVICE_VENDOR, valueSize, value, NULL);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    printf("\tDevice manufacturer: %s\n", value);
                    free(value);

                    // Hardware device version
                    result = clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, 0, NULL, &valueSize);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    value = (char*)malloc(valueSize);

                    result = clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, valueSize, value, NULL);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    printf("\tHardware version: %s\n", value);
                    free(value);

                    // Software driver version
                    result = clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, 0, NULL, &valueSize);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    value = (char*)malloc(valueSize);

                    result = clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, valueSize, value, NULL);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    printf("\tSoftware version: %s\n", value);
                    free(value);

                    // Open Cl version
                    result = clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, 0, NULL, &valueSize);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    value = (char*)malloc(valueSize);

                    result = clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, valueSize, value, NULL);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    printf("\tOpenCL C version: %s\n", value);
                    free(value);

                    printf("\n");
                }
                free(devices);
            }

            printf("Press enter to continue...");
            getch();
        }
        else if (menu_pick == 2) {
            // run benchmarks

            for (int i = 0; i < platformCount; i++) {
                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, NULL, NULL, &valueSize);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                value = (char*)malloc(valueSize);

                result = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, valueSize, value, NULL);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                printf("Platform name: %s\n", value);
                free(value);

                // Get all devices
                result = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &deviceCount);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                devices = (cl_device_id*)malloc(sizeof(cl_device_id) * deviceCount);

                result = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, deviceCount, devices, NULL);
                if (result != CL_SUCCESS)
                    printf("%s\n", getErrorString(result));

                for (int j = 0; j < deviceCount; j++) {
                    result = clGetDeviceInfo(devices[j], CL_DEVICE_NAME, 0, NULL, &valueSize);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    value = (char*)malloc(valueSize);

                    result = clGetDeviceInfo(devices[j], CL_DEVICE_NAME, valueSize, value, NULL);
                    if (result != CL_SUCCESS)
                        printf("%s\n", getErrorString(result));

                    printf("\tDevice name: %s\n", value);
                    free(value);

                    cl_int ret;
                    LARGE_INTEGER start;
                    LARGE_INTEGER stop;
                    LARGE_INTEGER frequency;
                    int i;
                    int* A = (int*)malloc(sizeof(int) * vector_len);
                    int* B = (int*)malloc(sizeof(int) * vector_len);
                    for (i = 0; i < vector_len; i++) {
                        A[i] = i;
                        B[i] = vector_len - i;
                    }

                    for (int x = 0; x < 2; x++) {
                        // Create an OpenCL context
                        cl_context context = clCreateContext(NULL, 1, &devices[j], NULL, NULL, &ret);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        // Create a command queue
                        cl_command_queue command_queue = clCreateCommandQueue(context, devices[j], 0, &ret);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        // Create memory buffers on the device for each vector 
                        cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, vector_len * sizeof(int), NULL, &ret);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, vector_len * sizeof(int), NULL, &ret);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, vector_len * sizeof(int), NULL, &ret);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));


                        // Copy the lists A and B to their respective memory buffers
                        ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, vector_len * sizeof(int), A, 0, NULL, NULL);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, vector_len * sizeof(int), B, 0, NULL, NULL);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        // Create a program from the kernel source
                        const char* source = kernelSourceCodeMultiply;
                        const size_t source_size = sizeof(kernelSourceCodeMultiply);
                        cl_program program = clCreateProgramWithSource(context, 1, &source, &source_size, &ret);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        // Build the program
                        ret = clBuildProgram(program, 1, &devices[j], NULL, NULL, NULL);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        // Create the OpenCL kernel
                        cl_kernel kernel = clCreateKernel(program, "matrixMul", &ret);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        //TEMP
                        int A = 1024;
                        int B = 1024;
                        // Set the arguments of the kernel
                        ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&b_mem_obj);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&c_mem_obj);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clSetKernelArg(kernel, 3, sizeof(int), (void*)&A);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clSetKernelArg(kernel, 4, sizeof(int), (void*)&B);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        //ret = clSetKernelArg(kernel, 3, sizeof(int), (void *)&vector_len);

                        // Execute the OpenCL kernel on the list
                        // def rozmiaru NDRange
                        // rozmiar globalny
                        size_t global_item_size = vector_len; // Process the entire lists//
                        size_t local_item_size = 64; // Divide work items into groups of 64

                        QueryPerformanceFrequency(&frequency);
                        QueryPerformanceCounter(&start);
                        //uruchomienie kernela na NDRange
                        ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clFinish(command_queue);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        QueryPerformanceCounter(&stop);

                        // Read the memory buffer C on the device to the local variable C
                        int* C = (int*)malloc(sizeof(int) * vector_len);
                        // Read the result
                        ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, vector_len * sizeof(int), C, 0, NULL, NULL);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        // Display the result to the screen
                        //for (i = 0; i < vector_len; i++)
                        //    printf("%d + %d = %d\n", A[i], B[i], C[i]);

                        // Clean up
                        ret = clReleaseKernel(kernel);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clReleaseProgram(program);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clReleaseMemObject(a_mem_obj);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clReleaseMemObject(b_mem_obj);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clReleaseMemObject(c_mem_obj);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clReleaseCommandQueue(command_queue);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        ret = clReleaseContext(context);
                        if (ret != CL_SUCCESS)
                            printf("%s\n", getErrorString(ret));

                        free(C);

                        printf("NDRange 1024 performance - time: %f\n\n", (double)(stop.QuadPart - start.QuadPart) / frequency.QuadPart);
                    }

                    free(A);
                    free(B);
                }
                free(devices);
            }

            printf("Press enter to continue...");
            getch();
        }
        else continue;
    }

    free(platforms);

    return 0;


}