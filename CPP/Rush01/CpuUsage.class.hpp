#include <stdio.h>
#include <unistd.h>
#include <mach/mach_host.h>
#include <mach/processor_info.h>
#include <iostream>

#ifndef CPUUSAGE_CLASS_HPP
#define CPUUSAGE_CLASS_HPP

class CpuUsage {
	public:
		CpuUsage(int core): core_(core) {
			prev = updated_ticks_(core);
		}

		float get() {
			Ticks t = updated_ticks_(core_);
			unsigned long long int used = t.used() - prev.used();
			unsigned long long int total = t.total() - prev.total();
			prev = t;
			if (!total)
				return 42;
			return static_cast<float>(used) / static_cast<float>(total) * 100.0f;
		}

	private:
		struct Ticks {
			unsigned long long int usertime;
			unsigned long long int nicetime;
			unsigned long long int systemtime;
			unsigned long long int idletime;

			unsigned long long int used() { return usertime + nicetime + systemtime; }
			unsigned long long int total() { return usertime + nicetime + systemtime + idletime; }
		} prev;

		int core_;

		Ticks updated_ticks_(int core)
		{
			unsigned int cpu_count;
			processor_cpu_load_info_t cpu_load;
			mach_msg_type_number_t cpu_msg_count;

			int rc =  host_processor_info(
					mach_host_self(),
					PROCESSOR_CPU_LOAD_INFO,
					&cpu_count,
					reinterpret_cast<processor_info_array_t *>(&cpu_load),
					&cpu_msg_count
					);
			if (rc != 0)
			{
			}
			unsigned long long int usertime = cpu_load[core].cpu_ticks[CPU_STATE_USER];
			unsigned long long int nicetime = cpu_load[core].cpu_ticks[CPU_STATE_NICE];
			unsigned long long int systemtime = cpu_load[core].cpu_ticks[CPU_STATE_SYSTEM];
			unsigned long long int idletime = cpu_load[core].cpu_ticks[CPU_STATE_IDLE];

			Ticks t = {usertime, nicetime, systemtime, idletime};
			return t;
		}
};

#endif
