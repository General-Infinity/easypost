#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (!argv[1]) {
    printf("Error: You did not specify a link to post to!\n");
    return 1;
  }
  char var1[100], var2[100];
  char post[201];
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    printf("name of the var:\n");
    gets(var1);
    strcat(post, var1);
    strcat(post, "=");
    printf("what are you going to post:\n");
    gets(var2);
    strcat(post, var2);
    printf(post);
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
