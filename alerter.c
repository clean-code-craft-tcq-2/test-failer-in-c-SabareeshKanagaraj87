#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int TriggerNetworkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

int TriggerNetworkAlert(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if (celcius <= 400) 
        return 200;
    else
        return 500;
}

void alertInCelcius(float farenheit, int (*Fptr_TriggerNetworkAlert)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = Fptr_TriggerNetworkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5, TriggerNetworkAlert);
    alertInCelcius(303.6, TriggerNetworkAlertStub);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 2);
    printf("All is well (maybe!)\n");
    return 0;
}
