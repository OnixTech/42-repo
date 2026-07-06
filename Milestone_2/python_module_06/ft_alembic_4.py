import alchemy


print("=== Alembic 4 ===")
print("Accesing alchemy module using 'import alchemy'")
print(f"Testing create air: {alchemy.elements.create_air()}")
print("Now show that not all functions can be reached")
print("This will raise an exception!")
print("Testing the hidden create earth: Traceback (most recent call last):")
print(alchemy.create_earth())
