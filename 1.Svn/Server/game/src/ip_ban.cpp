//Find
		int hash()
		{
			return (dwStart & 0x000000FF);
		}
		
///Add
#ifdef _ENABLE_IPBAN_
		const char* GetIP()
		{
			struct in_addr in_ip;
			in_ip.s_addr = dwStart;
			return inet_ntoa(in_ip);
		}
#endif

//Find
bool IsBanIP(struct in_addr in)
{
	...
	...
}

///Add
#ifdef _ENABLE_IPBAN_
void AddBanIP(const char* ip)
{
	const char* filename = "/usr/game/auth/BANIP";
	FILE* fp = fopen(filename, "w");
	if (fp) {
		for (const auto & [f,s] : mapBanIP)
			for (auto getip : s)
				fprintf(fp, "%s\n", getip.GetIP());
		fprintf(fp, "%s\n", ip);
		fclose(fp);
	}
	else {
		sys_log(0, "cannot open BANIP");
		return;
	}
}
#endif
