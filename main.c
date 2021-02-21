#include <stdio.h>
#include <curl/curl.h>
 
int main(int argc, char *argv[])
{
  char var1[100], var2[100];
  char post[201];
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    printf("name of the var:\n");
    scanf("%s", var1);
    strcat(post, var1);
    strcat(post, "=");
    printf("what are you going to post:\n");
    scanf("%s", var2);
    strcat(post, var2);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}