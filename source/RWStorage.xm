#include <Railway/RWStorage.h>

RWStorage::RWStorage( Storage *object )
	:RWFolder( object )
{
	this->object_handle = 0xffffffff;
}

/*
void
RWStorage::update_mem_indicator()
{
	NSNumber					*avail_mem;
	NSNumber					*total_mem;
	PTPStorageInfoDataset		*dataset;
	LockdownConnectionRef		connection;
	
	if ( ( connection = lockdown_connect() ) )
	{
		dataset = [this->object storageInfoDataset];
		
		total_mem = ( NSNumber * )lockdown_copy_value( connection,
												  kLockdownDiskUsageDomainKey,
												  kLockdownTotalDiskCapacityKey );
		avail_mem = ( NSNumber * )lockdown_copy_value( connection,
												  kLockdownDiskUsageDomainKey,
												  kLockdownTotalDataAvailableKey );
		
		[dataset setMaxCapacity:[total_mem unsignedLongLongValue]];
		[dataset setFreeSpaceInBytes:[avail_mem unsignedLongLongValue]];
		
		[total_mem release];
		[avail_mem release];
		
		lockdown_disconnect( connection );
	}
}*/