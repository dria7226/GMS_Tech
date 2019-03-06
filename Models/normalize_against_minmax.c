var normalized_value = 0.0;
if(TO_NORMALIZE > NORMAL_MAX)
{
    normalized_value = 1.0;
}

if(TO_NORMALIZE < NORMAL_MIN)
{
    normalized_value = 0.0;
}

normalized_value = (TO_NORMALIZE - (NORMAL_MIN))/(NORMAL_MAX - (NORMAL_MIN));