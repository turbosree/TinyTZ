// -----------------------------------------------------------------------------
/// \file                  tzdata2013d_template.c
/// \brief                 File access interceptor code
///                        Implements the access to tzdata binary db
/// \author                Sreejith.Naarakathil@gmail.com
// -----------------------------------------------------------------------------

int tz_access(const char *path, int amode)
{
   int ret = -1;                
   debug_print ("Access %s\n",path);
   if(locale_localtime)
   {
      ret = 0; /* Return success */
   }           
   return ret;

}

int tz_open(const char *path, int oflag, ... )
{
   int ret = -1;                
   debug_print ("Open %s\n",path);
   if(locale_localtime)
   {
      ret = 1; /* Return a non-zero non-neg value */
   }           
   return ret;
}

ssize_t tz_read(int fildes, void *buf, size_t nbyte)
{
   ssize_t ret = 0;
   switch(fildes)
   {
      case 1:
         {
            if(locale_localtime)
            {
               ret = locale_localtime_len;
               memcpy(buf,locale_localtime,locale_localtime_len);
            }
         }
         break;
      default:
         break;
   }
   debug_print ("Read fildes:%d nbyte:%d ret:%d\n",fildes,nbyte,ret);
   return ret;
}

int tz_close(int fildes)
{
   debug_print ("Close %d\n",fildes);
   return 0;
}

char *tz_getenv(const char *name)
{
   char *tz = NULL;
   debug_print ("Getenv %s\n",name);
   if(locale_localtime)
   {
      debug_print ("Getenv::locale_tz_id:%d locale_tz_names:%s\n",locale_tz_id, locale_tz_names[locale_tz_id]);
      tz = locale_tz_names[locale_tz_id];
   }
   return tz;
}

int tz_dump(void)
{
   int i = 0;
   debug_print("\nlocale_localtime: %d\n", locale_localtime_len);
   if(locale_localtime)
   {
      for(i = 0; i < locale_localtime_len; i++)
      {
         debug_print("%#x", locale_localtime[i]);
      }
   }
   debug_print("\nLength: %d\n", i);
   return i;
}

void tz_set_time_zone(int tz_id)
{
   locale_tz_id = tz_id;
   (*tz_set_fp[tz_id])();
}

